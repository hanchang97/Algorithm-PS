class Solution {
    fun solution(board: Array<IntArray>, moves: IntArray): Int {
        var answer = 0
        var height = board.size
        var moves = moves

        var resultList = mutableListOf<Int>()

        moves.forEach {
            var searchIndex = it-1

            var doll = 0
            for(i in 0..height-1){
                if(board[i][searchIndex] != 0){
                    doll = board[i][searchIndex]
                    board[i][searchIndex] = 0
                    break
                }
            }

            if(doll != 0){
                resultList.add(doll)
                if(resultList.size >= 2){
                    if(resultList[resultList.size-1] == resultList[resultList.size-2]){
                        var last = resultList.size-1
                        resultList.removeAt(last)
                        resultList.removeAt(last-1)
                        answer += 2
                    }
                }
            }
        }

        return answer
    }
}