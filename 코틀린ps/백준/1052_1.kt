import java.util.Scanner

fun main(args: Array<String>) {

    val sc: Scanner = Scanner(System.`in`)

    var N = sc.nextInt()
    var K = sc.nextInt()

    if(K == 1){  // 물병 1개 -> N + (추가물병) = 2의 제곱 형태 되어야 한다
        if(N == 1)
            println(0)
        else
            println(getBig(N) - N)
    }
    else{
        if(N==1){
            println(0)
        }
        else{
            for(count in 1..(K-1)){
                N -= getSmall(N)
                // println("N : ${N}")
                if(N == 1 || N == 0)  // K개 물병전에 N이 1 or 0이 되면!
                    break         // -> 0 : 애초에 N이 2의 거듭제곱으로 이루어짐, 1 : N-1이 2의 거듭제곱으로 이루어짐
            }

            if(N==1 || N == 0)
                println(0)
            else
                println(getBig(N) - N)
        }
    }
}

fun getBig(num: Int): Int{ // num 보다 크면서 num에 가장 가까운 2의 거듭제곱 수 반환 함수
    var pow = 2
    while(true){
        if(pow >= num)
            break
        pow *= 2
    }

    //println("big pow = ${pow}")
    return pow
}

fun getSmall(num: Int): Int{ // num 보다 작으면서 num에 가장 가까운 2의 거듭제곱 수 반환 함수

    var pow = 2
    while(true){
        if(pow * 2 > num)
            break
        pow *= 2
    }

    //println("small pow = ${pow}")
    return pow
}
