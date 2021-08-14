from collections import Counter


def backtrack(temp: list, s: list, count: Counter, i: int, t: int):
    if t == 0:
        print(temp)
        return

    if t <= 0:
        return

    for j in range(i, len(s)):
        if t - s[j] >= 0 and count[s[j]] > 0:
            temp.append(s[j])
            count[s[j]] -= 1
            backtrack(temp, s, count, j, t - s[j])
            temp.remove(s[j])
            count[s[j]] += 1


def main():
    t = 4
    s = [4, 3, 2, 2, 1, 1]
    temp = []
    count = Counter(s)
    s = sorted(list(set(s)))

    backtrack(temp, s, count, 0, t)


if __name__ == "__main__":
    main()
