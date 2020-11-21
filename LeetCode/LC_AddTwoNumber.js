function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

function getArray (listNode, tmpArr) {
    return !listNode 
        ? tmpArr 
        : getArray(listNode.next, tmpArr.concat([listNode.val]));
}

function addTwoNumbers (l1, l2) {
    let l1Str = getArray(l1, []).reverse().join('');
    let l2Str = getArray(l2, []).reverse().join('');
    
    let diffLen = l1Str.length - l2Str.length;
    
    let extendedStr = '0'.repeat(Math.abs(diffLen))
                         .concat(diffLen <= 0 ? l1Str : l2Str);
    
    let targetStr = (diffLen <= 0 ? l2Str : l1Str).toString();
    
    let sum = '';
    let isOverTen = false;
    for(let i = extendedStr.length - 1; i >= 0; i--) {
        let computed = parseInt(extendedStr[i]) + parseInt(targetStr[i]);
        if(isOverTen) {
            isOverTen = false;
            computed ++;
        }
        
        if(computed > 9) {
            computed -= 10;
            isOverTen = true;
        }
        sum = sum.concat(computed);
    }
    if(isOverTen) sum = sum.concat('1');

    let head = null;
    let res = null;
    
    for(let i = 0; i < sum.length; i++) {
        if(!res) {
            res = new ListNode(sum[i], null);
            head = res;
        } else {
            res.next = new ListNode(sum[i], null);
            res = res.next;
        }
    }
    return head;
};
