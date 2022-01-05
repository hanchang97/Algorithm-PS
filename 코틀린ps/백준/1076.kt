import java.util.Scanner

fun main(args: Array<String>) {

    val resistMap = mapOf(
        Pair("black", ResistValue(0,1)),
        Pair("brown", ResistValue(1,10)),
        Pair("red", ResistValue(2,100)),
        Pair("orange", ResistValue(3,1000)),
        Pair("yellow", ResistValue(4,10000)),
        Pair("green", ResistValue(5,100000)),
        Pair("blue", ResistValue(6,1000000)),
        Pair("violet", ResistValue(7,10000000)),
        Pair("grey", ResistValue(8,100000000)),
        Pair("white", ResistValue(9,1000000000))
    )

    val sc: Scanner = Scanner(System.`in`)

    var color10 = sc.nextLine()
    var color1 = sc.nextLine()
    var colorMul = sc.nextLine()

    println((resistMap.get(color10)!!.value * 10 + resistMap.get(color1)!!.value) * (resistMap.get(colorMul)!!.mul))
}

class ResistValue(value: Long, mul: Long){  // Int 범위가 넘어가므로 Long 타입 사용하기
    var value = value
    var mul = mul
}

