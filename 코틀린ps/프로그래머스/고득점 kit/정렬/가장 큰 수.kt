class Solution {
    fun solution(numbers: IntArray): String {
        var answer = ""

        var strList = numbers.map{it.toString()}

        strList = strList.sortedWith(Comparator<String>{first, second ->
            when{
                first + second < second + first -> 1 // 리스트에서 왼쪽 원소를 first라고 생각!, 1인 경우 first와 second 자리를 바꾼다고 생각
                first + second > second + first -> -1
                else -> 0  // 같은 경우 0을 리턴하도록 하자!!!
            }
        })

        if(strList[0] == "0") answer = "0"
        else{
            for(i in strList.indices){
                answer += strList[i]
            }
        }

        return answer
    }