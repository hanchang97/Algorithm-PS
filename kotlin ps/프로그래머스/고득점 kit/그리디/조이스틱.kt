class Solution {

    private var Min = 0

    fun solution(name: String): Int {

        var answer = 0

        Min = name.length - 1
        // 좌우 이동횟수는 (name 길이 - 1) (= 한 방향으로 쭉) 보다는 무조건 작거나 같게 된다

        // 상, 하 조작 횟수 계산
        for (i in 0..name.length - 1) {
            var gap = name[i] - 'A'
            if (gap >= 14) gap = 26 - gap

            answer += gap
        }

        // 좌, 우 조작 횟수 계산 - 브루트포스
        val initCheck = Array<Boolean>(name.length) { false }
        for (i in name.indices) {
            if (name[i] == 'A') initCheck[i] = true
        }

        getResult(0, 0, initCheck)

        answer += Min

        return answer
    }

    fun getResult(checkInx: Int, dist: Int, checkArr: Array<Boolean>) {

        if (dist >= Min) return // 더 이상 검사 할 필요 없음

        val copyCheckArr = checkArr.copyOf() // 꼬이지 않게 새로운 배열 생성
        copyCheckArr[checkInx] = true  // 이동을 해서 작업을 했다는 뜻

        var isAllA = true  // 모두 변환 완료되었는지 검사
        for (i in copyCheckArr.indices) {
            if (copyCheckArr[i] == false) {
                isAllA = false
                break
            }
        }

        if (isAllA) { // 모두 변환 완료
            Min = dist
            return
        } else {
            // 오른쪽 1칸 이동
            if (checkInx >= copyCheckArr.size - 1) getResult(0, dist + 1, copyCheckArr)
            else getResult(checkInx + 1, dist + 1, copyCheckArr)

            // 왼쪽 1칸 이동
            if (checkInx <= 0) getResult(copyCheckArr.size - 1, dist + 1, copyCheckArr)
            else getResult(checkInx - 1, dist + 1, copyCheckArr)

        }

    }
}

// n = name 길이
// 최대 ( 2 ^ n ) * n 시간복잡도
// 각 재귀마다 전체 변환이 완료되었는지 체크