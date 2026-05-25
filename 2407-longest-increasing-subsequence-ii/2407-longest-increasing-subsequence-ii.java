class Node {
    Node leftChild;
    Node rightChild;
    int start;
    int end;
    int value;

    public Node(int start, int end, int value) {
        this.start = start;
        this.end = end;
        this.value = value;
    }
}

class Solution {
    Node buildSegmentTree(int start, int end) {
        if (start == end)
            return new Node(start, end, 0);
        Node node = new Node(start, end, 0);
        int mid = (start + end) / 2;
        node.leftChild = buildSegmentTree(start, mid);
        node.rightChild = buildSegmentTree(mid + 1, end);
        return node;
    }

    int queryRangeMax(Node node, int l, int r) {
        if (node == null || l > node.end || r < node.start)
            return 0;
        if (l <= node.start && r >= node.end)
            return node.value;
        return Math.max(queryRangeMax(node.leftChild, l, r), queryRangeMax(node.rightChild, l, r));
    }

    void updateSegmentTree(Node node, int index, int value) {
        if (node == null || index < node.start || index > node.end)
            return; 
        node.value = Math.max(value, node.value);
        if (node.start != node.end) { 
            updateSegmentTree(node.leftChild, index, value);
            updateSegmentTree(node.rightChild, index, value);
        }
    }

    public int lengthOfLIS(int[] nums, int k) {
        Node root = buildSegmentTree(0, 100001);
        int ans = 1;
        for (int num : nums) {
            int maxValInRange = queryRangeMax(root, Math.max(0, num - k), num - 1) + 1;
            ans = Math.max(ans, maxValInRange);
            updateSegmentTree(root, num, maxValInRange);
        }
        return ans;
    }
}