import java.util.*

class Solution {
    fun solution(jobs: Array<IntArray>): Int {
        var answer = 0
        var time = 0
        var jobIndex = 0

        jobs.sortBy { it[0] }  // jobs 요청 시간 빠른 순 정렬

        var currentStartTime = -1 // 현재 진행중인 task 시작 시간

        // 소요시간 작은 것에 우선순위를 높게
        val pq = PriorityQueue<IntArray>(Comparator { arr1, arr2 ->
            when {
                arr1[1] > arr2[1] -> 1
                else -> -1
            }
        })

        while (jobIndex < jobs.size || !pq.isEmpty()) {
            if (jobs.size > jobIndex && time >= jobs[jobIndex][0]) {
                pq.add(jobs[jobIndex++])

                continue
            }

            if (!pq.isEmpty()) {
                time += pq.peek()[1]

                answer += (time - pq.peek()[0]) // 요청시간 ~ 완료시간

                pq.poll()
            } else {
                time = jobs[jobIndex][0]
            }

        }

        return answer / jobs.size
    }
}