fn add(int_one:i32,int_two:i32) -> i32 {
	int_one+int_two
}
static B: fn(i32,i32) -> i32 = add;
fn main() {
	print!("{}",B(10,20));
}
