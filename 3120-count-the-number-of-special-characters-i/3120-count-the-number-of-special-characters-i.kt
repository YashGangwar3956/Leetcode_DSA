class Solution {
        fun numberOfSpecialChars(w: String) = 
        w.toSet().count {it-32 in w}
}