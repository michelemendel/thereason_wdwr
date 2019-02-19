let items = [10, 11, 12, 13, 14, 15, 16];

let logList = ls => Js.log(Array.of_list(ls));

Js.log(List.length(items));
Js.log(Belt.List.size(items));

let sqrtPlusOne = x => sqrt(float_of_int(x) +. 1.0);

let roots = Belt.List.makeBy(5, sqrtPlusOne);
U.logList(roots);

let added1 = Belt.List.add(items, 9);
let added2 = [9, ...items];
U.logList(added1);
U.logList(added2);
/* Add to the end */
let added3 = Belt.List.concat(items, [9]);
logList(added3);

let more = [17, 18, 19];
let joined = Belt.List.concat(items, more);
U.logList(joined);