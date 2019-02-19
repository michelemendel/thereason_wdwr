open Belt.List;

let intReducer = (acc: string, curr: int) => {
  acc ++ string_of_int(curr) ++ ", ";
};

let stringOfIntList = (items: list(int)): string => {
  "[" ++ reduce(items, "", intReducer) ++ "]";
};

let items = [10, 11, 12, 13, 14, 15];

Js.log(stringOfIntList(items));