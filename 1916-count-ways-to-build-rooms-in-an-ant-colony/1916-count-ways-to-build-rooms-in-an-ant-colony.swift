
class Solution {
    let mod = 1_000_000_007

    func waysToBuildRooms(_ prevRoom: [Int]) -> Int {
        let n = prevRoom.count

        var g = Array(repeating: [Int](), count: n)

        for i in 1..<n {
            g[prevRoom[i]].append(i)
        }

        var fact = Array<Int64>(repeating: 1, count: n + 1)
        var invFact = Array<Int64>(repeating: 1, count: n + 1)

        for i in 1...n {
            fact[i] = fact[i - 1] * Int64(i) % Int64(mod)
        }

        func powMod(_ a: Int64, _ b: Int64) -> Int64 {
            var a = a
            var b = b
            var res: Int64 = 1

            while b > 0 {
                if b & 1 == 1 {
                    res = res * a % Int64(mod)
                }

                a = a * a % Int64(mod)
                b >>= 1
            }

            return res
        }

        invFact[n] = powMod(fact[n], Int64(mod - 2))

        if n > 0 {
            for i in stride(from: n - 1, through: 0, by: -1) {
                invFact[i] = invFact[i + 1] * Int64(i + 1) % Int64(mod)
            }
        }

        func comb(_ n: Int, _ r: Int) -> Int64 {
            if r < 0 || r > n {
                return 0
            }

            return fact[n] * invFact[r] % Int64(mod) * invFact[n - r] % Int64(mod)
        }

        func dfs(_ u: Int) -> (Int, Int64) {
            var ways: Int64 = 1
            var size = 0

            for v in g[u] {
                let (subSize, subWays) = dfs(v)

                ways = ways * subWays % Int64(mod)
                ways = ways * comb(size + subSize, subSize) % Int64(mod)

                size += subSize
            }

            return (size + 1, ways)
        }

        return Int(dfs(0).1)
    }
}

