class Solution {
    public int numberOfSpecialChars(String word) {
        return (int) Arrays.stream(word.split(""))
                .filter(s -> Character.isLowerCase(s.charAt(0)) && word.contains(String.valueOf(Character.toUpperCase(s.charAt(0)))))
                .distinct()
                .count();
    }
}