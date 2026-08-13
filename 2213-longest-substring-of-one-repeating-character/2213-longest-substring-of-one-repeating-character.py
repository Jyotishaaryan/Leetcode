class Solution:
    def longestRepeating(self, s, queryCharacters, queryIndices):
        n = len(s)

        size = 1
        while size < n:
            size <<= 1

        N = size * 2

        left = [0] * N
        right = [0] * N
        pref = [0] * N
        suff = [0] * N
        best = [0] * N
        length = [0] * N

        # Leaves
        for i, c in enumerate(s):
            p = size + i
            x = ord(c)

            left[p] = x
            right[p] = x
            pref[p] = 1
            suff[p] = 1
            best[p] = 1
            length[p] = 1

        # Build
        for p in range(size - 1, 0, -1):
            l = p << 1
            r = l | 1

            length[p] = length[l] + length[r]

            left[p] = left[l]
            right[p] = right[r]

            if right[l] == left[r]:

                if pref[l] == length[l]:
                    pref[p] = length[l] + pref[r]
                else:
                    pref[p] = pref[l]

                if suff[r] == length[r]:
                    suff[p] = length[r] + suff[l]
                else:
                    suff[p] = suff[r]

                x = best[l]
                if best[r] > x:
                    x = best[r]

                cross = suff[l] + pref[r]
                if cross > x:
                    x = cross

                best[p] = x

            else:
                pref[p] = pref[l]
                suff[p] = suff[r]

                best[p] = best[l]
                if best[r] > best[p]:
                    best[p] = best[r]

        ans = []

        for c, idx in zip(queryCharacters, queryIndices):

            p = size + idx
            x = ord(c)

            left[p] = x
            right[p] = x
            pref[p] = 1
            suff[p] = 1
            best[p] = 1

            p >>= 1

            while p:

                l = p << 1
                r = l | 1

                length[p] = length[l] + length[r]
                left[p] = left[l]
                right[p] = right[r]

                if right[l] == left[r]:

                    if pref[l] == length[l]:
                        pref[p] = length[l] + pref[r]
                    else:
                        pref[p] = pref[l]

                    if suff[r] == length[r]:
                        suff[p] = length[r] + suff[l]
                    else:
                        suff[p] = suff[r]

                    x = best[l]

                    if best[r] > x:
                        x = best[r]

                    cross = suff[l] + pref[r]

                    if cross > x:
                        x = cross

                    best[p] = x

                else:
                    pref[p] = pref[l]
                    suff[p] = suff[r]

                    x = best[l]

                    if best[r] > x:
                        x = best[r]

                    best[p] = x

                p >>= 1

            ans.append(best[1])

        return ans