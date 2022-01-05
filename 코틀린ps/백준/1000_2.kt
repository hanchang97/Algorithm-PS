import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args : Array<String>){
    val br = BufferedReader(InputStreamReader(System.`in`))

    var inputList = br.readLine().split(' ').map{it.toInt()}

    println(inputList[0] + inputList[1])
}

// Scanner를 사용한 코드와 시간은 동일하게 120ms 나왔다