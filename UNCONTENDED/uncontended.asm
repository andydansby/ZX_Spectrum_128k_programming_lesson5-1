;; UNCONTENDED

;SECTION UNCONTENDED

;;uncontended memory from 32768 to 49151
;; 16383 bytes total

;;__fastcall__ fastcall
;; Fastcall linkage allows one parameter
;; to be passed by register in a subset of DEHL.
;; So if the parameter is 8-bit, the value will
;; be in L.  If the parameter is 16-bit,
;; the value is in HL and if it is
;; 32-bit the value is in DEHL.

SECTION code_user
; assign read-only executable code to this section
;----------------------------------
;attention new, we moved
PUBLIC _border_Change_IM2
_border_Change_IM2:
    ld hl, (_ada)   ; loads L of HL with the variable ada
    ld a, l         ;
    and 7           ; mask with 0000 0111
    out ($FE),a
    inc a           ;; increment value
    ld (_ada), a    ; and update variable _ada
ret


PUBLIC _border_Change_uncontended
_border_Change_uncontended:
    ld a, l     ;contents of l are loaded into a
    out (254), a
ret

SECTION rodata_user
; assign read-only data to this section
;; Variables
;; define C variables here to force placement in memory
PUBLIC _xyzzy2
_xyzzy2:
    defb 254
;----------------------------------

SECTION smc_user
; assign self-modifying code to this section
;----------------------------------

SECTION data_user
; assign non-zero initial data to this section
;----------------------------------

SECTION bss_user
; assign zero initial data to this section
;----------------------------------
;;attention new moved
PUBLIC _ada
_ada:
defb 0



