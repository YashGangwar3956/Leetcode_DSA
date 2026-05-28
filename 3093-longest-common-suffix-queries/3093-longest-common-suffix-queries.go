type TrieNode struct {
    children [26]*TrieNode
    bestLen  int
    bestIdx  int
}

func stringIndices(wordsContainer []string, wordsQuery []string) []int {
    root := &TrieNode{
        bestLen: 1e9,
        bestIdx: 1e9,
    }
    
    for i, word := range wordsContainer {
        n := len(word)
        curr := root
        
        if n < curr.bestLen || (n == curr.bestLen && i < curr.bestIdx) {
            curr.bestLen = n
            curr.bestIdx = i
        }
        
        for j := n - 1; j >= 0; j-- {
            charIdx := word[j] - 'a'
            
            if curr.children[charIdx] == nil {
                curr.children[charIdx] = &TrieNode{
                    bestLen: 1e9,
                    bestIdx: 1e9,
                }
            }
            
            curr = curr.children[charIdx]
            
            if n < curr.bestLen || (n == curr.bestLen && i < curr.bestIdx) {
                curr.bestLen = n
                curr.bestIdx = i
            }
        }
    }
    
    ans := make([]int, len(wordsQuery))
    
    for i, query := range wordsQuery {
        curr := root
        n := len(query)
        
        for j := n - 1; j >= 0; j-- {
            charIdx := query[j] - 'a'
            
            if curr.children[charIdx] == nil {
                break
            }
            curr = curr.children[charIdx]
        }
        
        ans[i] = curr.bestIdx
    }
    
    return ans
} 