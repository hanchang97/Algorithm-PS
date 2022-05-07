class Solution {

    lateinit var graphComputer: Array<ArrayList<Int>>
    lateinit var visitCheck: Array<Boolean>

    fun dfs(node: Int){

        visitCheck[node] = true // 방문체크!

        for(i in 0..graphComputer[node].size - 1){
            var next = graphComputer[node][i]

            if(visitCheck[next] == false) dfs(next) // 재귀 사용
        }

    }


    fun solution(n: Int, computers: Array<IntArray>): Int {

        var answer = 0

        if(computers.size == 1) return 1  // 노드 1개 = 네트워크 1개

        graphComputer = Array(computers.size){arrayListOf()}
        visitCheck = Array(computers.size){false}

        for(i in 0..computers.size - 2){
            for(j in (i+1)..computers.size - 1){
                if(computers[i][j] == 1){
                    graphComputer[i].add(j)
                    graphComputer[j].add(i)
                }
            }
        }

        for(i in 0..computers.size - 1){
            if(visitCheck[i] == false){
                answer++
                dfs(i)
            }
        }

        return answer
    }

}