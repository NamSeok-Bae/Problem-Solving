import Foundation

func solution(_ book_time:[[String]]) -> Int {
var roomCnt = 0
var room = [String]()

func makeMinute(s: String) -> Int {
    let time = s.split(separator: ":").map {Int(String($0))!}
    let hour = time[0]
    
    return hour * 60 + time[1]
}

let temp = book_time.sorted {
    return makeMinute(s: $0[0]) < makeMinute(s: $1[0])
}

temp.forEach { element in
    if room.isEmpty {
        room.append(element[1])
        roomCnt += 1
    } else {
        if let idx = room.firstIndex(where: {
            makeMinute(s: $0) + 10 <= makeMinute(s: element[0])
        }) {
            room[idx] = element[1]
        } else {
            room.append(element[1])
            roomCnt += 1
        }
    }
}
    
    return roomCnt
}