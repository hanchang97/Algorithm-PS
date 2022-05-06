class Solution {
    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
        var answer = 0

        var lostCount = lost.size

        lost.sort()
        reserve.sort()

        val reserveMap = mutableMapOf<Int, Int>()
        val lostMap = mutableMapOf<Int, Int>()
        for (i in 0..reserve.size - 1) {
            reserveMap[reserve[i]] = 1
        }
        for (i in 0..lost.size - 1) {
            lostMap[lost[i]] = 1
            if (reserveMap[lost[i]] == 1) {
                lostMap[lost[i]] = -1
                reserveMap[lost[i]] = -1
                lostCount--
            }
        }

        for (i in 0..lost.size - 1) {
            if (lostMap[lost[i]] == 1) {
                if (lost[i] >= 2) {
                    val front = lost[i] - 1

                    if (reserveMap[front] == 1) {
                        reserveMap[front] = -1
                        lostCount--
                        continue
                    }

                }
                if (lost[i] < n) {
                    val back = lost[i] + 1
                    if (reserveMap[back] == 1) {
                        reserveMap[back] = -1
                        lostCount -= 1
                    }
                }
            }
        }

        answer = n - lostCount

        return answer
    }
}

/*
- lost [ 7, 5] ,  reserve[6, 8] 인 경우
- 정렬이 안되면 학생7은 학생6에게 빌리게된다
- 학생5는  4, 6 이 여벌이 있는지 보게되는데 6이 이미 7에게 빌려줘서 5는 체육복 빌릴 수 없다
- 근데 7은 8에게도 빌릴 수 있고, 8에게 빌리면 5가 6에게 빌릴 수 있게 된다

- 잃어버린 사람의 앞, 뒤를 차례로 보는 흐름이므로 두 배열이 초기에 정렬이 되어있어야 한다!!!!
*/