function solution(new_id) {
    const answer = new_id
        .toLowerCase()
        .replace(/[^\w-_.]/g, '')
        .replace(/\.+/g, '.')
        .replace(/^\.|\.$/g, '')    
        .replace(/^$/, 'a')
        .slice(0, 15)
        .replace(/\.$/, '');
    
    const length = answer.length;
    return length > 2 
        ? answer
        : answer + answer.charAt(length - 1).repeat(3 - length);
}
