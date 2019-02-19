open Belt;

let orderList = [
  (7, ShirtSize.Medium),
  (5, ShirtSize.XLarge(3)),
  (4, ShirtSize.Small),
  (6, ShirtSize.Large),
  (8, ShirtSize.Small),
  (2, ShirtSize.Large),
  (9, ShirtSize.Medium),
  (3, ShirtSize.XLarge(2)),
];

/* Map */

let onePrice = ((qty: int, size: ShirtSize.t)): float => {
  float_of_int(qty) *. ShirtSize.price(size);
};
let priceList = List.map(orderList, onePrice);

U.logList(priceList);

/* Keep */

let isMedium = ((_, size)): bool => {
  size === ShirtSize.Medium;
};
let mediums = List.keep(orderList, isMedium);
U.logList(mediums);

/* Reduce */

let addPriceLogged = (runningTotal, orderItem) => {
  runningTotal +. onePrice(orderItem);
};

Js.log("Running total / Price");
let totalPrice = List.reduce(orderList, 0.0, addPriceLogged);
Js.log2("Total price:", totalPrice);

/* Total price v2 */

let addPriceToTotal = (runningTotal, price) => runningTotal +. price;
let totalPrice2 =
  List.map(orderList, onePrice)->List.reduce(_, 0.0, addPriceToTotal);
Js.log2("Total price:", totalPrice2);