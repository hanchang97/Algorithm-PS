class Solution {
    fun solution(answers: IntArray): IntArray {
        var answer = intArrayOf(0,0,0)

        var supo1 = intArrayOf(1,2,3,4,5)
        var supo2 = intArrayOf(2,1,2,3,2,4,2,5)
        var supo3 = intArrayOf(3,3,1,1,2,2,4,4,5,5)

        var index = 0
        answers.forEach {
            if(supo1[index % 5] == it)
                answer[0]++
            if(supo2[index % 8] == it)
                answer[1]++
            if(supo3[index % 10] == it)
                answer[2]++

            index++
        }

        var answerWithIndex = mutableListOf<Pair<Int, Int>>(Pair(answer[0], 1), Pair(answer[1], 2), Pair(answer[2], 3))
        answerWithIndex.sortWith(compareBy({it.first}, {-it.second}))

        var maxValue = answerWithIndex[2].first

        var answerList = mutableListOf<Int>()
        for(i in 2 downTo 0){
            if(answerWithIndex[i].first == maxValue)
                answerList.add(answerWithIndex[i].second)
        }

        return answerList.toIntArray()  //
    }
}