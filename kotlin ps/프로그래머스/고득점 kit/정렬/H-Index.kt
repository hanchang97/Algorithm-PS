class Solution {
    fun solution(citations: IntArray): Int {
        val result = citations.sortedArrayDescending()  // 내림차순 정렬
        for (i in 0 until result.size) {
            if (result[i] < i + 1) {
                // 내림차순 정렬되어있으므로 0~i-1 인덱스는 i보다 크거나 같음이 보장!!
                return i  // 이전 원소들은 자신이 몇번째 있는 값보다 크거나 같았다
            }
        }

        return citations.size
    }
}

/* 기존 풀이

class Solution {
    fun solution(citations: IntArray): Int {
        var answer = 0

        val ascendingSorted = citations.sortedWith(Comparator<Int>{first, second ->
            when{
                first > second -> 1
                first < second -> -1
                else -> 0
            }
        })
        // 오름차순 정렬을 했음

        if(ascendingSorted.size == 1){  // 크기 1일때 대비
            if(ascendingSorted[0] >= 1) return 1
            else return 0
        }

        for(i in 1..ascendingSorted.size){

             if(ascendingSorted[ascendingSorted.size - i] < i) break

            if(i < ascendingSorted.size && ascendingSorted[ascendingSorted.size - i] >= i &&
                    ascendingSorted[ascendingSorted.size - i - 1] <= i) answer = i
        }

        if(ascendingSorted[0] >= ascendingSorted.size){
            answer = ascendingSorted.size
        }

        return answer
    }
}

*  */