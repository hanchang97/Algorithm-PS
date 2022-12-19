fun main() = with(System.`in`.bufferedReader()) {
    var (R, C, N) = readLine().split(' ').map { it.toInt() }

    val originBoard = Array(R) { Array(C) { Bomb() } }
    val dy = intArrayOf(-1, 1, 0, 0)
    val dx = intArrayOf(0, 0, -1, 1)

    repeat(R) { row ->
        val data = readLine()
        data.forEachIndexed { column, char ->
            if (char == 'O') {
                originBoard[row][column].apply {// 초기 설치
                    isBomb = true
                    time = 0
                }
            }
        }
    }

    // 1초 : 아무것도 안하고 기존에 설치된 폭탄 시간만 증가
    for (i in 0 until R) {
        for (j in 0 until C) {
            if (originBoard[i][j].isBomb) {
                originBoard[i][j].time++
            }
        }
    }

    // N 감소
    N--

    if (N >= 1) {
        while (true) {
            // 미설치 공간에 폭탄 설치하기, 기존 폭탄은 시간 증가
            for (i in 0 until R) {
                for (j in 0 until C) {
                    originBoard[i][j].apply {
                        if (isBomb) {
                            time++
                        } else {
                            isBomb = true
                            time = 0
                        }
                    }
                }
            }

            N--
            if (N == 0) break

            // 3초 전에 설치된 폭탄 폭발, 인접 공간 포함
            val checkBoard = Array(R) { IntArray(C) { 0 } }
            for (i in 0 until R) {
                for (j in 0 until C) {
                    if (originBoard[i][j].isBomb) {
                        originBoard[i][j].time++

                        if (originBoard[i][j].time == 3) {
                            checkBoard[i][j] = 1
                            (0..3).forEach {
                                val nextY = i + dy[it]
                                val nextX = j + dx[it]
                                if (nextY in 0 until R && nextX in 0 until C) {
                                    checkBoard[nextY][nextX] = 1
                                }
                            }
                        }
                    }
                }
            }

            for (i in 0 until R) {
                for (j in 0 until C) {
                    if (checkBoard[i][j] >= 1) {
                        originBoard[i][j].apply {
                            isBomb = false
                            time = 0
                        }
                    }
                }
            }

            N--
            if (N == 0) break
        }
    }

    // 출력
    for (i in 0 until R) {
        for (j in 0 until C) {
            originBoard[i][j].run {
                if (isBomb) print("O")
                else print(".")
            }
        }
        println()
    }
}

data class Bomb(
    var isBomb: Boolean = false,
    var time: Int = 0
)