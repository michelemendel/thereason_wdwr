let sickDays =
  Belt.Map.String.fromArray([|("David", 4), ("Cathy", 2), ("Felipe", 1)|]);

let persons = ["David", "Cathy", "Felipe", "Joe", "Paracelsus"];

let logSD = (sickDays, who) => {
  let days = Belt.Map.String.get(sickDays, who);
  Js.log({j|$who: $days|j});
};

let logSickdays = sdList => {
  let names = Array.to_list(Belt.Map.String.keysToArray(sdList));
  let _ = List.map(logSD(sdList), names);
  Js.log("---");
};

let outSick =
  fun
  | Some(n) => Some(n + 1)
  | None => Some(1);

let remove = (_days: option(int)): option(int) => None;

let result1 = Belt.Map.String.update(sickDays, "Cathy", outSick);
/* ("David", 4) ("Cathy", 3) ("Felipe", 1) */
let result2 = Belt.Map.String.update(sickDays, "Joe", outSick);
/* ("David", 4) ("Cathy", 2) ("Felipe", 1) ("Joe", 1) */
let result3 = Belt.Map.String.update(sickDays, "David", remove);
/* ("Cathy", 2) ("Felipe", 1) */
let result4 = Belt.Map.String.update(sickDays, "Paracelsus", remove);
/* ("David", 4) ("Cathy", 2) ("Felipe", 1) */

logSickdays(sickDays);
logSickdays(result1);
logSickdays(result2);
logSickdays(result3);
logSickdays(result4);

/* Js.log2("r1: ", result1);
   Js.log2("r2: ", result2);
   Js.log2("r3: ", result3);
   Js.log2("r4: ", result4); */