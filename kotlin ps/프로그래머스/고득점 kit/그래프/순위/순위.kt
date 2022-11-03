class Solution {
    fun solution(n: Int, results: Array<IntArray>): Int {
        var answer = 0

        val INF = 10000

        val board = Array(n + 1) { IntArray(n + 1) { INF } }

        results.forEach {
            val win = it[0]
            val lose = it[1]

            board[win][lose] = 1
            board[lose][win] = -1 // 음수인 경로는 이동 불가
        }

        for (k in 1..n) {
            for (i in 1..n) {
                for (j in 1..n) {
                    if (board[i][k] > 0 && board[k][j] > 0) {
                        if (board[i][k] + board[k][j] < board[i][j]) {
                            val dist = board[i][k] + board[k][j]
                            board[i][j] = dist
                            board[j][i] = dist * -1
                        }
                    }
                }
            }
        }

        for (i in 1 until n + 1) {
            if (board[i].count { it < INF } == n - 1)
                answer++
        }

        return answer
    }
}