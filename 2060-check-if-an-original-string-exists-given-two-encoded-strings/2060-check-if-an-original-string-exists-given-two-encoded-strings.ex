
defmodule Solution do
  @spec possibly_equals(s1 :: String.t(), s2 :: String.t()) :: boolean
  def possibly_equals(s1, s2) do
    a = String.to_charlist(s1)
    b = String.to_charlist(s2)

    {ans, _} = dfs(a, b, 0, 0, 0, %{})
    ans
  end

  defp dfs(a, b, i, j, diff, memo) do
    key = {i, j, diff}

    case Map.get(memo, key) do
      nil ->
        {res, memo} = solve(a, b, i, j, diff, memo)
        {res, Map.put(memo, key, res)}

      v ->
        {v, memo}
    end
  end

  defp solve(a, b, i, j, diff, memo) do
    n = length(a)
    m = length(b)

    cond do
      i >= n and j >= m and diff == 0 ->
        {true, memo}

      true ->
        {res1, memo} =
          if i < n do
            ch = Enum.at(a, i)

            cond do
              digit?(ch) ->
                parse_a(a, b, i, j, diff, memo)

              diff > 0 ->
                dfs(a, b, i + 1, j, diff - 1, memo)

              diff == 0 and j < m and ch == Enum.at(b, j) ->
                dfs(a, b, i + 1, j + 1, diff, memo)

              true ->
                {false, memo}
            end
          else
            {false, memo}
          end

        if res1 do
          {true, memo}
        else
          if j < m do
            ch = Enum.at(b, j)

            cond do
              digit?(ch) ->
                parse_b(a, b, i, j, diff, memo)

              diff < 0 ->
                dfs(a, b, i, j + 1, diff + 1, memo)

              true ->
                {false, memo}
            end
          else
            {false, memo}
          end
        end
    end
  end

  defp parse_a(a, b, i, j, diff, memo) do
    n = length(a)

    Enum.reduce_while(0..2, {false, memo, 0}, fn k, {_, memo, num} ->
      if i + k < n and digit?(Enum.at(a, i + k)) do
        num = num * 10 + Enum.at(a, i + k) - ?0

        {res, memo} = dfs(a, b, i + k + 1, j, diff - num, memo)

        if res do
          {:halt, {true, memo, num}}
        else
          {:cont, {false, memo, num}}
        end
      else
        {:halt, {false, memo, num}}
      end
    end)
    |> then(fn {res, memo, _} -> {res, memo} end)
  end

  defp parse_b(a, b, i, j, diff, memo) do
    m = length(b)

    Enum.reduce_while(0..2, {false, memo, 0}, fn k, {_, memo, num} ->
      if j + k < m and digit?(Enum.at(b, j + k)) do
        num = num * 10 + Enum.at(b, j + k) - ?0

        {res, memo} = dfs(a, b, i, j + k + 1, diff + num, memo)

        if res do
          {:halt, {true, memo, num}}
        else
          {:cont, {false, memo, num}}
        end
      else
        {:halt, {false, memo, num}}
      end
    end)
    |> then(fn {res, memo, _} -> {res, memo} end)
  end

  defp digit?(c), do: c >= ?0 and c <= ?9
end