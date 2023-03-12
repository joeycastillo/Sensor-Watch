#![no_std]

mod sensorwatch;
use sensorwatch::movement_event_t;

#[no_mangle]
pub extern "C" fn rust_add(left: u32, right: u32) -> u32 {
    left + right
}

#[no_mangle]
pub extern "C" fn corrosion_face_loop(event: movement_event_t) {
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}

#[panic_handler]
fn my_panic(_info: &core::panic::PanicInfo) -> ! {
    loop {}
}
