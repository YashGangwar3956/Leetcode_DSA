
# @param {Integer[]} nums
# @return {Integer}
def number_of_good_subsets(nums)
    mod = 1_000_000_007
    primes = [2,3,5,7,11,13,17,19,23,29]

    cnt = Array.new(31, 0)

    nums.each do |x|
        cnt[x] += 1
    end

    masks = Array.new(31, -1)

    (2..30).each do |x|
        t = x
        mask = 0
        ok = true

        primes.each_with_index do |p, i|
            c = 0

            while t % p == 0
                t /= p
                c += 1
            end

            if c > 1
                ok = false
                break
            end

            mask |= (1 << i) if c == 1
        end

        masks[x] = mask if ok
    end

    dp = Array.new(1 << 10, 0)
    dp[0] = 1

    (2..30).each do |x|
        next if cnt[x] == 0 || masks[x] == -1

        mask = masks[x]

        ndp = dp.dup

        (0...(1 << 10)).each do |s|
            next if (s & mask) != 0

            ndp[s | mask] = (ndp[s | mask] + dp[s] * cnt[x]) % mod
        end

        dp = ndp
    end

    ans = 0

    (1...(1 << 10)).each do |s|
        ans = (ans + dp[s]) % mod
    end

    pow = 1

    cnt[1].times do
        pow = (pow * 2) % mod
    end

    (ans * pow) % mod
end

