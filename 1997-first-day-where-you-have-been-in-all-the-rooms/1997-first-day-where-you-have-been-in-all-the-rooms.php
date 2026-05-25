
class Solution {

    /**
     * @param Integer[] $nextVisit
     * @return Integer
     */
    function firstDayBeenInAllRooms($nextVisit) {
        $mod = 1000000007;
        $n = count($nextVisit);

        $dp = array_fill(0, $n, 0);

        for ($i = 1; $i < $n; $i++) {
            $dp[$i] = (
                (2 * $dp[$i - 1]) % $mod
                - $dp[$nextVisit[$i - 1]]
                + 2
                + $mod
            ) % $mod;
        }

        return $dp[$n - 1];
    }
}
