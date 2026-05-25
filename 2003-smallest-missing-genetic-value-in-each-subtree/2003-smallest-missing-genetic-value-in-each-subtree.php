
class Solution {

    /**
     * @param Integer[] $parents
     * @param Integer[] $nums
     * @return Integer[]
     */
    function smallestMissingValueSubtree($parents, $nums) {
        $n = count($parents);

        $graph = array_fill(0, $n, []);

        $nodeOne = -1;

        for ($child = 0; $child < $n; $child++) {
            $parent = $parents[$child];

            if ($parent != -1) {
                $graph[$parent][] = $child;
            }

            if ($nums[$child] == 1) {
                $nodeOne = $child;
            }
        }

        $results = array_fill(0, $n, 1);

        if ($nodeOne == -1) {
            return $results;
        }

        $seen = array_fill(0, 100002, false);

        $currentNode = $nodeOne;
        $missing = 1;

        while ($currentNode != -1) {
            $this->markSeen($currentNode, $graph, $seen, $nums);

            while ($missing < 100002 && $seen[$missing]) {
                $missing++;
            }

            $results[$currentNode] = $missing;

            $currentNode = $parents[$currentNode];
        }

        return $results;
    }

    function markSeen($node, &$graph, &$seen, &$nums) {
        if ($seen[$nums[$node]]) {
            return;
        }

        $seen[$nums[$node]] = true;

        foreach ($graph[$node] as $child) {
            $this->markSeen($child, $graph, $seen, $nums);
        }
    }
}
