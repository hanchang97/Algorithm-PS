class Solution {
    fun solution(rows: Int, columns: Int, queries: Array<IntArray>): IntArray {

        var answer = IntArray(queries.size){0}  // answer 배열도 queries 와 사이즈 같음, 우선 0으로 모두 초기화

        val Map = Array(rows){IntArray(columns){0}}
        var num = 1
        for(i in Map.indices){
            for(j in Map[i].indices){
                Map[i][j] = num++
            }
        }

        for(i in queries.indices){ // 쿼리 만큼 반복
            val y1 = queries[i][0] - 1  // 인덱스 기준 좌표
            val x1 = queries[i][1] - 1
            val y2 = queries[i][2] - 1
            val x2 = queries[i][3] - 1

            val topRightTemp = Map[y1][x2]
            val bottomRightTemp = Map[y2][x2]
            val bottomLeftTemp = Map[y2][x1]
            val topLeftTemp = Map[y1][x1]

            // 윗줄 오른쪽으로 밀기, 현재 위치의 값은 왼쪽에 있는 값이 된다
            for(x in x2 downTo (x1+1)){
                Map[y1][x] = Map[y1][x-1]
            }

            // 오른쪽줄 아래로 밀기, 현재 위치의 값은 위(이전 위치)의 값이 된다
            for(y in y2 downTo (y1+1)){
                if(y == y1+1){
                    Map[y][x2] = topRightTemp // 윗줄 바뀌기 전 상태의 값을 넣어줘야 한다
                }
                else{
                    Map[y][x2] = Map[y-1][x2]
                }
            }

            // 아랫줄 왼쪽으로 밀기
            for(x in x1..(x2-1)){
                if(x == x2-1){
                    Map[y2][x] = bottomRightTemp
                }
                else{
                    Map[y2][x] = Map[y2][x+1]
                }
            }

            // 왼쪽줄 위로 밀기
            for(y in y1..(y2-1)){
                if(y == y2-1){
                    Map[y][x1] = bottomLeftTemp
                }
                else{
                    Map[y][x1] = Map[y+1][x1]
                }
            }

            // check
            /*  
            for(k in Map.indices){
                  for(t in Map[k].indices){
                      print(Map[k][t])
                      print(" ")
                  }
                  println()
              }
              */

            // 최솟값 찾고 추가하기
            var min = 100000
            for(x in x1..x2){ // 윗줄, 아랫줄 동시 반복
                if(Map[y1][x] < min) min = Map[y1][x]
                if(Map[y2][x] < min) min = Map[y2][x]
            }
            for(y in (y1+1)..(y2-1)){
                if(Map[y][x1] < min) min = Map[y][x1]
                if(Map[y][x2] < min) min = Map[y][x2]
            }

            answer[i] = min
        }

        return answer
    }
}