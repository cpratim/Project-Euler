(* Pratim Chowdhary 03/13/23 *)

let s = ref 0;;
let max = 1000;;

for n = 1 to max do
  if n mod 3 = 0 || n mod 5 = 0 then
    s := !s + n;
done;

print_string "Problem 1 Solution: ";;
print_string (string_of_int !s);;