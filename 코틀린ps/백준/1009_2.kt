import java.util.Scanner

fun main(args: Array<String>) {
    val sc: Scanner = Scanner(System.`in`)

    var testCase = sc.nextInt()

    for(testCount in 1..testCase){
        var a = sc.nextInt()  // 1~99
        var b = sc.nextInt()

        if(a % 10 == 0){
            println(10)
            continue
        }

        var result = 1
        for(i in 1..b){
            result = result * a % 10
        }
        println(result)
    }
}




