data class TruckData(
    var weight: Int, // 무게
    var current: Int // 시간, 다리 올라가면서 1 할당
)

class Solution {
    fun solution(bridge_length: Int, weight: Int, truck_weights: IntArray): Int {
        var answer = 0
        var al_remain = ArrayList<TruckData>()  // 대기
        var al_bridge = ArrayList<TruckData>()  // 다리를 지나는 중
        var al_arrive = ArrayList<TruckData>()  // 다리를 모두 지남

        truck_weights.forEach {
            al_remain.add(TruckData(it, 0))
        }

        var currentSum = 0

        while (al_arrive.size < truck_weights.size) {  // 모든 트럭이 다리를 지나 도착하는 순간 까지

            answer++  // 총 소요시간 1씩 증가

            // 다리 위 트럭들 시간 1개씩 증가
            al_bridge.forEach {
                it.current++
            }

            if (al_bridge.size != 0) {
                if (al_bridge[0].current > bridge_length) {
                    // 현재 다리에서 맨 먼저 올라갔던 트럭이 다리를 모두 지나갔는지 체크
                    currentSum -= al_bridge[0].weight
                    al_arrive.add(TruckData(al_bridge[0].weight, al_bridge[0].current))
                    al_bridge.removeAt(0)
                }
            }

            if (al_remain.size != 0) {
                if (currentSum + al_remain[0].weight <= weight) {
            // 대기 트럭 중 맨 앞의 트럭이 현재 다리에 올라올 수 있는지 체크
                    al_bridge.add(TruckData(al_remain[0].weight, 1))
                    currentSum += al_remain[0].weight
                    al_remain.removeAt(0)
                }
            }

        }

        return answer
    }
}