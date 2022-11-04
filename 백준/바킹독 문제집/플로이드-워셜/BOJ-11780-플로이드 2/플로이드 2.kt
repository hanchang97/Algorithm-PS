fun main() = with(System.`in`.bufferedReader()) {
    val N = readLine().toInt()
    var M = readLine().toInt()

    val INF = 100000000

    val board = Array(N + 1) { IntArray(N + 1) { INF } }
    val route = Array(N + 1) { IntArray(N + 1) { 0 } }

    while (M > 0) {
        val info = readLine().split(" ").map { it.toInt() }
        val start = info[0]
        val end = info[1]
        val dist = info[2]

        if (dist < board[start][end]) {
            board[start][end] = dist
            route[start][end] = end
        }
        M--
    }

    for (i in 1 until N + 1)
        board[i][i] = 0

    for (k in 1 until N + 1) {
        for (i in 1 until N + 1) {
            for (j in 1 until N + 1) {
                if (board[i][k] + board[k][j] < board[i][j]) {
                    board[i][j] = board[i][k] + board[k][j]
                    route[i][j] = route[i][k]
                }
            }
        }
    }

    for (i in 1 until N + 1) {
        for (j in 1 until N + 1) {
            if (board[i][j] == INF) {
                print("0 ")
                board[i][j] = 0
            } else {
                print("${board[i][j]} ")
            }
        }
        println()
    }

    for (i in 1 until N + 1) {
        for (j in 1 until N + 1) {
            if (board[i][j] == 0) print("0")
            else {
                val routeList = ArrayList<Int>()
                var next = route[i][j]
                routeList.add(i)
                routeList.add(next)

                while(next != j) {
                    next = route[next][j]
                    routeList.add(next)
                }

                print(routeList.size)
                routeList.forEach{
                    print(" ${it}")
                }
            }
            println()
        }
    }
}