
fun main() = with(System.`in`.bufferedReader()) {
    val inf = 10000000
    val N = readLine().toInt()
    val board = Array(N) { IntArray(N) { inf } }

    for(i in 0 until N) board[i][i] = 0

    var M = readLine().toInt()

    while (M > 0) {
        val info = readLine().split(" ").map{ it.toInt() }
        val a = info[0] - 1
        val b = info[1] - 1
        val c = info[2]
        board[a][b] = if (board[a][b] < c) board[a][b] else c
        M--
    }

    for(k in 0 until N) {
        for(i in 0 until N) {
            for(j in 0 until N) {
                if(board[i][k] + board[k][j] < board[i][j])
                    board[i][j] = board[i][k] + board[k][j]
            }
        }
    }

    for(i in board.indices) {
        for(j in board.indices) {
            if(board[i][j] == inf) print("0 ")
            else print("${board[i][j]} ")
        }
        println()
    }
}



