class Solution {
    fun solution(clothes: Array<Array<String>>): Int {
        var answer = 1

        clothes.groupBy{it[1]}.forEach{ key, value ->
            answer *= value.size + 1
        }

        return answer - 1
    }
}