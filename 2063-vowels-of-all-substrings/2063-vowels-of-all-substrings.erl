
-spec count_vowels(Word :: unicode:unicode_binary()) -> integer().
count_vowels(Word) ->
    Chars = unicode:characters_to_list(Word),
    Len = length(Chars),
    count(Chars, 0, Len, 0).

is_vowel($a) -> true;
is_vowel($e) -> true;
is_vowel($i) -> true;
is_vowel($o) -> true;
is_vowel($u) -> true;
is_vowel(_) -> false.

count([], _, _, Ans) ->
    Ans;

count([H | T], Pos, Len, Ans) ->
    Add =
        case is_vowel(H) of
            true -> (Len - Pos) * (Pos + 1);
            false -> 0
        end,
    count(T, Pos + 1, Len, Ans + Add).