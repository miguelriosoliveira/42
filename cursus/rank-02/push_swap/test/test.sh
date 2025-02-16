./push_swap > test/empty.received
diff -s test/empty.expected test/empty.received

./push_swap word > test/error_single_non_int.received 2>&1
diff -s test/error.expected test/error_single_non_int.received

./push_swap 0 one 2 3 > test/error_contains_non_int.received 2>&1
diff -s test/error.expected test/error_contains_non_int.received

# INT_MAX = 2147483647
./push_swap 2147483648 > test/error_greater_than_INT_MAX.received 2>&1
diff -s test/error.expected test/error_greater_than_INT_MAX.received

# INT_MIN = -2147483648
./push_swap -2147483649 > test/error_lower_than_INT_MIN.received 2>&1
diff -s test/error.expected test/error_lower_than_INT_MIN.received

./push_swap 0 1 2 3 2 > test/error_contains_duplicates.received 2>&1
diff -s test/error.expected test/error_contains_duplicates.received

./push_swap 3 03 > test/error_contains_duplicates_with_zero.received 2>&1
diff -s test/error.expected test/error_contains_duplicates_with_zero.received

./push_swap 0 1 2 3 > test/ok_numbers.received
diff -s test/empty.expected test/ok_numbers.received

./push_swap "0 1 2 3" > test/ok_string.received
diff -s test/empty.expected test/ok_string.received

./push_swap "0 1 2       3" > test/ok_string_with_spaces.received
diff -s test/empty.expected test/ok_string_with_spaces.received

./push_swap 1 2 3 > test/123.received
diff -s test/empty.expected test/123.received

./push_swap 1 3 2 > test/132.received
diff -s test/132.expected test/132.received

./push_swap 2 1 3 > test/213.received
diff -s test/213.expected test/213.received

./push_swap 2 3 1 > test/231.received
diff -s test/231.expected test/231.received

./push_swap 3 1 2 > test/312.received
diff -s test/312.expected test/312.received

./push_swap 3 2 1 > test/321.received
diff -s test/321.expected test/321.received

./push_swap 5 2 7 1 6 3 9 4 8 > test/527163948.received
diff -s test/527163948.expected test/527163948.received

check_push_swap() {
	local ARG="$1"
	local ARG_ARR=($1) # Convert string to an array (split on spaces)
	local expected_moves="$2"
	local size=${#ARG_ARR[@]}  # Get array size

	result=$(./push_swap $ARG)
	is_sorted=$(echo "$result" | ./checker_$(uname) $ARG)

	if [ "$is_sorted" = "OK" ]; then
		received_moves=$(echo "$result" | wc -l | tr -d '[:space:]')

		if [ "$received_moves" -le "$expected_moves" ]; then
			echo "✅ $size numbers properly sorted in $received_moves moves (max $expected_moves)"
		else
			echo "❌ $size numbers properly sorted, but in $received_moves moves (max $expected_moves)"
		fi
	else
		echo "❌ Numbers not properly sorted"
	fi
}

ARG="-2147483648 2147483647 -221 358 204 62 242 -79 -327 402 -431 -248 -427 212 -24 -323 -359 461 -51 451 305 -160 106 -45 -367 202 -113 229 -106 -286 99 373 -38 101 -485 -395 -197 -57 166 -467 420 -424 -445 -33 -447 302 173 -126 438 -358 -351 427 306 357 377 -265 70 45 359 136 -164 -493 394 -255 489 236 13 -141 23 -27 39 367 449 -2 -74 -90 301 -335 399 -191 50 -14 123 268 199 396 26 492 -117 -182 172 315 401 -25 -458 -91 -281 -77 317 -372 41 288"
check_push_swap "$ARG" 699

ARG="-2147483648 2147483647 26 1 -233 -338 -223 16 6 -202 385 -35 -251 176 165 135 -232 -486 -77 -419 -473 -492 -20 448 -337 -392 -36 -144 -240 -263 227 -411 134 -335 120 235 -407 179 106 245 -131 -287 -292 -285 488 377 -417 461 126 450 -311 -465 -34 413 -167 93 -418 483 -234 215 419 -146 -27 86 -342 330 462 -378 -82 -397 -326 -153 -209 -388 231 256 -297 423 -176 82 415 156 -476 409 168 -500 -284 327 196 149 -175 40 71 -133 494 -183 287 355 98 313 369 350 221 124 -139 414 2 158 50 238 267 186 264 209 74 143 -171 366 331 -29 -479 188 -112 128 -174 370 395 -413 316 -383 404 45 -206 -42 232 -230 -387 336 -106 -105 -412 460 -323 -101 18 268 -432 -367 -400 -320 341 -72 425 -481 116 440 -17 402 278 -11 27 -64 91 61 153 -68 362 96 -198 -436 -331 -360 -250 -211 493 207 -8 459 42 -302 -178 -308 306 271 435 -428 -309 100 -84 -124 200 189 -301 -107 3 -336 383 -157 -18 476 -1 73 261 -179 -406 -398 90 -441 -310 217 361 138 -85 -276 -453 363 -371 418 195 -151 -246 224 -130 360 129 -421 -271 30 -349 495 -381 451 -401 190 492 -92 365 157 -218 183 -415 272 -80 -91 -184 -63 -389 -304 -204 293 -61 -45 489 -156 -333 255 329 453 -108 276 -6 -437 -109 46 -253 -224 5 285 286 -467 -484 283 -447 359 -488 262 130 260 -113 115 -192 -399 -353 -318 -208 -470 230 155 471 466 326 301 20 -444 -163 430 10 405 -314 -489 -182 117 -193 112 -164 13 347 438 222 -391 17 -463 -480 -345 43 25 -88 447 -69 -366 -181 -237 -122 142 -141 -214 -97 398 197 21 -145 -332 -90 -330 353 -280 -272 389 -50 34 7 121 182 36 -140 -121 -185 -446 246 177 358 465 -123 23 -226 -96 -188 -431 -459 342 410 203 -62 -147 -475 333 412 180 -13 -196 269 -298 -22 380 49 312 274 212 -238 -4 371 -227 -120 422 490 -187 -76 290 -434 491 -316 -70 265 -110 -464 315 194 -306 396 443 -429 478 84 321 31 -334 48 -132 -117 487 -194 -386 -23 191 -277 486 -215 39 -275 119 -118 -374 -150 -454 322 -225 22 456 -252 318 -376 294 -403 -350 -295 -21 -261 444 -195 -126 -286 -268 399 468 401 442 308 -363 24 65 367 -129 277 78 479 63 -495 77 474 -47 348 295 -44 4 337 52 407 -452 455 133 424 -99 250 -358 -165 -66 -296 187 -416 -95 334 -159 70 94 -258 -3 -33 228 127 -245 206 -135 280 335 -60 279 -359 292 343 -220 -438 -32"
check_push_swap "$ARG" 5500
