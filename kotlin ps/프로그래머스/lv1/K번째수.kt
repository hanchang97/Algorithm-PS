class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        var answer = intArrayOf()

        var answerList = mutableListOf<Int>()
        var commandCount = commands.size
        for(i in 0..commandCount-1){
            var start = commands[i][0] - 1
            var end = commands[i][1] - 1
            var searchIndex = commands[i][2] - 1

            var tempList = mutableListOf<Int>()
            for( j in start..end){
                tempList.add(array[j])
            }

            tempList.sort()
            answerList.add(tempList[searchIndex])
        }

        return answerList.toIntArray()  //
    }
}