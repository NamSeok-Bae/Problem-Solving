func solution(_ phone_number:String) -> String {
    return phone_number.enumerated().map {
        if $0.offset < phone_number.count - 4 {
            return "*"
        }
        return String($0.element)
    }.joined()
}