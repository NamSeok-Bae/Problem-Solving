//
//  main.swift
//  알고리즘
//
//  Created by 배남석 on 2023/11/22.
//

func solution(_ arr:[Int]) -> Double {
    
    var sum: Int = 0
    for i in arr {
        sum += i;
    }
    
    return Double(Double(sum) / Double(arr.count))
}
