fun main() = with(System.`in`.bufferedReader()) {
    // 1. dp table 채우기
    // 2. sum(ey, ex, sy, sx) = table[ey][ex] - table[sy-1][ex] - table[ey][sx-1] + table[sy-1][sx-1]

    val (N, M) = readLine().split(' ').map { it.toInt() }
    val table = Array(N + 1) { IntArray(N + 1) { 0 } } // 인덱스 처리 편의성을 위해 N+1 로 선언

    for (i in 1..N) {
        val numList = readLine().split(' ').map { it.toInt() }
        numList.forEachIndexed { j, value ->
            table[i][j + 1] = value + table[i - 1][j + 1] + table[i][j] - table[i - 1][j]
        }
    }

    repeat(M) {
        val (sy, sx, ey, ex) = readLine().split(' ').map { it.toInt() }
        val ans =
            table[ey][ex] - table[sy - 1][ex] - table[ey][sx - 1] + table[sy - 1][sx - 1]
        println(ans)
    }
}