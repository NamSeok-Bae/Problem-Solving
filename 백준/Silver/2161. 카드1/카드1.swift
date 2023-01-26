//
//  main.swift
//  백준
//
//  Created by 배남석 on 2021/07/16.
//

import Foundation

var a = Int(readLine()!)!

var arr = [Int]()

var result = [Int]()

for i in 0..<a {
    arr.append(i+1)
}

while true {
    result.append(arr.remove(at: 0))
    if arr.count == 0 {
        break
    }
    numberChange()
}

func numberChange() {
    var tmp: Int = 0
    tmp = arr.remove(at: 0)
    arr.append(tmp)
}
print(result.map{"\($0)"}.joined(separator: " "))
