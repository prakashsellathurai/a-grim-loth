import os
from urllib.request import pathname2url
import sys
import argparse

# Sorts files by their name. Directories come first. 
def sort_files(a, b):
    if a == b:
        return 0
    if a == None or b == None:
        return -1 if a == None else 1;
    left, right = os.path.isdir(a), os.path.isdir(b)
    if left == right:
        return -1 if a < b else 1;
    return -1 if left else 1;


# Creates a line of text for a directory entry.
def directory_line(file_name, full_path, level):
    has_readme = os.path.isfile(os.path.join(full_path, 'README.md'))
    return ('\t' * level) + '- ' + (file_name if not has_readme else '[%s](%s)' % (file_name, pathname2url(full_path)))

# Creates a line of text for a file entry.
def file_line(file_name, full_path, level):
    return ('\t' * level) + '- [%s](%s)' % (os.path.splitext(file_name)[0], pathname2url(full_path))


    
# Walks a given directory to create a TOC out of it.
def walk_directory(path = '.', exclude = ['.github','.git', '.idea','.exe'], level = 0):
    result, files = [], os.listdir(path)

    exclude_files = ['CONTRIBUTING.md','README.md','generate_toc.py','generate-markdown.yaml','.github','.gitignore','LICENSE']
    # Sort by directory/name
    files.sort()
    for file_name in files:
        full_path = os.path.join(path, file_name)
        # Skip the file if its in the exclude list.
        if file_name in exclude: continue
        elif file_name in exclude_files: continue
        elif 'utils' in full_path: continue
        elif os.path.isdir(full_path):
            result.append(directory_line(file_name, full_path, level))
            result.extend(walk_directory(full_path, exclude, level + 1))
        elif file_name != 'README.md' :
            result.append(file_line(file_name, full_path, level))
    return result

def replace_toc(file_path, toc, toc_start, toc_end):
    toc_file = open(file_path, 'r').read()
    start, end =toc_file.find(toc_start), toc_file.find(toc_end);
    return (toc_file[:start + len(toc_start)]) + ("\n\n%s\n\n" % toc) + (toc_file[end:]);



parser = argparse.ArgumentParser()
parser.add_argument("--readme", help="Searches and replaces the lines between toc-start and toc-end in the given file and prints the output. If not given, the script just prints the TOC generated.", default="./README.md")
parser.add_argument("--target", help="Target folder to create TOC for.", default=".");
parser.add_argument("--exclude", help="List of folder and file names to exclude.", default=['.git', '.idea'], type=str, nargs='+');
parser.add_argument("--toc-start", help="Start of the TOC.", default="[//]: # (TOCSTART)");
parser.add_argument("--toc-end", help="End of the TOC.", default="[//]: # (TOCEND)");
args = parser.parse_args()

result = "\n".join(walk_directory(args.target, args.exclude));

if args.readme == None:
    sys.stdout.write(result);
else:
    result=replace_toc(args.readme, result, args.toc_start, args.toc_end);
    with open('README.md', 'w') as fout:
        fout.writelines(result)
sys.stdout.flush();