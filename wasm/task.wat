(module
  (type (;0;) (func (result i32)))
  (type (;1;) (func (param f32 f32) (result f32)))
  (type (;2;) (func))
  (type (;3;) (func (param i32) (result i32)))
  (type (;4;) (func (param i32)))
  (type (;5;) (func (param i32 i32) (result i32)))
  (type (;6;) (func (param i32 i32 i32) (result i32)))
  (type (;7;) (func (param i32 i64 i32) (result i64)))
  (func (;0;) (type 2)
    call 12)
  (func (;1;) (type 1) (param f32 f32) (result f32)
    (local i32 i32 i32 f32 f32 f32)
    global.get 0
    local.set 2
    i32.const 16
    local.set 3
    local.get 2
    local.get 3
    i32.sub
    local.set 4
    local.get 4
    local.get 0
    f32.store offset=12
    local.get 4
    local.get 1
    f32.store offset=8
    local.get 4
    f32.load offset=12
    local.set 5
    local.get 4
    f32.load offset=8
    local.set 6
    local.get 5
    local.get 6
    f32.add
    local.set 7
    local.get 7
    return)
  (func (;2;) (type 1) (param f32 f32) (result f32)
    (local i32 i32 i32 f32 f32 f32)
    global.get 0
    local.set 2
    i32.const 16
    local.set 3
    local.get 2
    local.get 3
    i32.sub
    local.set 4
    local.get 4
    local.get 0
    f32.store offset=12
    local.get 4
    local.get 1
    f32.store offset=8
    local.get 4
    f32.load offset=12
    local.set 5
    local.get 4
    f32.load offset=8
    local.set 6
    local.get 5
    local.get 6
    f32.sub
    local.set 7
    local.get 7
    return)
  (func (;3;) (type 1) (param f32 f32) (result f32)
    (local i32 i32 i32 f32 f32 f32)
    global.get 0
    local.set 2
    i32.const 16
    local.set 3
    local.get 2
    local.get 3
    i32.sub
    local.set 4
    local.get 4
    local.get 0
    f32.store offset=12
    local.get 4
    local.get 1
    f32.store offset=8
    local.get 4
    f32.load offset=12
    local.set 5
    local.get 4
    f32.load offset=8
    local.set 6
    local.get 5
    local.get 6
    f32.mul
    local.set 7
    local.get 7
    return)
  (func (;4;) (type 1) (param f32 f32) (result f32)
    (local i32 i32 i32 i32 i32 i32 i32 f32 f32 f32 f32 f32 f32 f32)
    global.get 0
    local.set 2
    i32.const 16
    local.set 3
    local.get 2
    local.get 3
    i32.sub
    local.set 4
    local.get 4
    local.get 0
    f32.store offset=8
    local.get 4
    local.get 1
    f32.store offset=4
    local.get 4
    f32.load offset=4
    local.set 9
    i32.const 0
    local.set 5
    local.get 5
    f32.convert_i32_s
    local.set 10
    local.get 9
    local.get 10
    f32.eq
    local.set 6
    i32.const 1
    local.set 7
    local.get 6
    local.get 7
    i32.and
    local.set 8
    block  ;; label = @1
      block  ;; label = @2
        local.get 8
        i32.eqz
        br_if 0 (;@2;)
        f32.const -0x1p+0 (;=-1;)
        local.set 11
        local.get 4
        local.get 11
        f32.store offset=12
        br 1 (;@1;)
      end
      local.get 4
      f32.load offset=8
      local.set 12
      local.get 4
      f32.load offset=4
      local.set 13
      local.get 12
      local.get 13
      f32.div
      local.set 14
      local.get 4
      local.get 14
      f32.store offset=12
    end
    local.get 4
    f32.load offset=12
    local.set 15
    local.get 15
    return)
  (func (;5;) (type 0) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    local.set 0
    i32.const 16
    local.set 1
    local.get 0
    local.get 1
    i32.sub
    local.set 2
    i32.const 27
    local.set 3
    local.get 2
    local.get 3
    i32.store offset=12
    block  ;; label = @1
      loop  ;; label = @2
        local.get 2
        i32.load offset=12
        local.set 4
        i32.const 0
        local.set 5
        local.get 4
        local.set 6
        local.get 5
        local.set 7
        local.get 6
        local.get 7
        i32.ge_s
        local.set 8
        i32.const 1
        local.set 9
        local.get 8
        local.get 9
        i32.and
        local.set 10
        local.get 10
        i32.eqz
        br_if 1 (;@1;)
        local.get 2
        i32.load offset=12
        local.set 11
        local.get 2
        i32.load offset=12
        local.set 12
        i32.const 1024
        local.set 13
        i32.const 2
        local.set 14
        local.get 12
        local.get 14
        i32.shl
        local.set 15
        local.get 13
        local.get 15
        i32.add
        local.set 16
        local.get 16
        i32.load
        local.set 17
        local.get 17
        local.get 11
        i32.xor
        local.set 18
        local.get 16
        local.get 18
        i32.store
        local.get 2
        i32.load offset=12
        local.set 19
        i32.const -1
        local.set 20
        local.get 19
        local.get 20
        i32.add
        local.set 21
        local.get 2
        local.get 21
        i32.store offset=12
        br 0 (;@2;)
      end
      unreachable
    end
    i32.const 0
    local.set 22
    local.get 2
    local.get 22
    i32.store offset=8
    block  ;; label = @1
      loop  ;; label = @2
        local.get 2
        i32.load offset=8
        local.set 23
        i32.const 28
        local.set 24
        local.get 23
        local.set 25
        local.get 24
        local.set 26
        local.get 25
        local.get 26
        i32.lt_s
        local.set 27
        i32.const 1
        local.set 28
        local.get 27
        local.get 28
        i32.and
        local.set 29
        local.get 29
        i32.eqz
        br_if 1 (;@1;)
        local.get 2
        i32.load offset=8
        local.set 30
        i32.const 27
        local.set 31
        local.get 31
        local.get 30
        i32.sub
        local.set 32
        local.get 2
        i32.load offset=8
        local.set 33
        i32.const 1024
        local.set 34
        i32.const 2
        local.set 35
        local.get 33
        local.get 35
        i32.shl
        local.set 36
        local.get 34
        local.get 36
        i32.add
        local.set 37
        local.get 37
        i32.load
        local.set 38
        local.get 38
        local.get 32
        i32.xor
        local.set 39
        local.get 37
        local.get 39
        i32.store
        local.get 2
        i32.load offset=8
        local.set 40
        i32.const 1
        local.set 41
        local.get 40
        local.get 41
        i32.add
        local.set 42
        local.get 2
        local.get 42
        i32.store offset=8
        br 0 (;@2;)
      end
      unreachable
    end
    i32.const 1024
    local.set 43
    local.get 43
    local.set 44
    local.get 2
    local.get 44
    i32.store offset=4
    i32.const 0
    local.set 45
    local.get 2
    local.get 45
    i32.store
    block  ;; label = @1
      loop  ;; label = @2
        local.get 2
        i32.load
        local.set 46
        i32.const 28
        local.set 47
        local.get 46
        local.set 48
        local.get 47
        local.set 49
        local.get 48
        local.get 49
        i32.lt_s
        local.set 50
        i32.const 1
        local.set 51
        local.get 50
        local.get 51
        i32.and
        local.set 52
        local.get 52
        i32.eqz
        br_if 1 (;@1;)
        local.get 2
        i32.load
        local.set 53
        i32.const 1024
        local.set 54
        i32.const 2
        local.set 55
        local.get 53
        local.get 55
        i32.shl
        local.set 56
        local.get 54
        local.get 56
        i32.add
        local.set 57
        local.get 57
        i32.load
        local.set 58
        local.get 2
        i32.load offset=4
        local.set 59
        local.get 2
        i32.load
        local.set 60
        local.get 59
        local.get 60
        i32.add
        local.set 61
        local.get 61
        local.get 58
        i32.store8
        local.get 2
        i32.load
        local.set 62
        i32.const 1
        local.set 63
        local.get 62
        local.get 63
        i32.add
        local.set 64
        local.get 2
        local.get 64
        i32.store
        br 0 (;@2;)
      end
      unreachable
    end
    local.get 2
    i32.load offset=4
    local.set 65
    local.get 65
    return)
  (func (;6;) (type 3) (param i32) (result i32)
    (local i32 i32 i32 i32 i32 i32 i32 i32 i32 i32)
    global.get 0
    local.set 1
    i32.const 16
    local.set 2
    local.get 1
    local.get 2
    i32.sub
    local.set 3
    local.get 3
    local.get 0
    i32.store offset=12
    local.get 3
    i32.load offset=12
    local.set 4
    i32.const 1024
    local.set 5
    i32.const 2
    local.set 6
    local.get 4
    local.get 6
    i32.shl
    local.set 7
    local.get 5
    local.get 7
    i32.add
    local.set 8
    local.get 8
    i32.load
    local.set 9
    local.get 3
    local.get 9
    i32.store offset=8
    local.get 3
    i32.load offset=8
    local.set 10
    local.get 10
    return)
  (func (;7;) (type 0) (result i32)
    (local i32 i32 i32 i32 i32)
    global.get 0
    local.set 0
    i32.const 16
    local.set 1
    local.get 0
    local.get 1
    i32.sub
    local.set 2
    i32.const 0
    local.set 3
    local.get 2
    local.get 3
    i32.store offset=12
    i32.const 0
    local.set 4
    local.get 4
    return)
  (func (;8;) (type 5) (param i32 i32) (result i32)
    (local i32)
    call 7
    local.set 2
    local.get 2
    return)
  (func (;9;) (type 0) (result i32)
    global.get 0)
  (func (;10;) (type 4) (param i32)
    local.get 0
    global.set 0)
  (func (;11;) (type 3) (param i32) (result i32)
    (local i32 i32)
    global.get 0
    local.get 0
    i32.sub
    i32.const -16
    i32.and
    local.tee 1
    global.set 0
    local.get 1)
  (func (;12;) (type 2)
    i32.const 5244032
    global.set 2
    i32.const 1152
    i32.const 15
    i32.add
    i32.const -16
    i32.and
    global.set 1)
  (func (;13;) (type 0) (result i32)
    global.get 0
    global.get 1
    i32.sub)
  (func (;14;) (type 0) (result i32)
    global.get 2)
  (func (;15;) (type 0) (result i32)
    global.get 1)
  (func (;16;) (type 4) (param i32))
  (func (;17;) (type 0) (result i32)
    i32.const 1136
    call 16
    i32.const 1140)
  (func (;18;) (type 3) (param i32) (result i32)
    i32.const 1)
  (func (;19;) (type 2)
    (local i32)
    block  ;; label = @1
      call 17
      i32.load
      local.tee 0
      i32.eqz
      br_if 0 (;@1;)
      loop  ;; label = @2
        local.get 0
        call 20
        local.get 0
        i32.load offset=56
        local.tee 0
        br_if 0 (;@2;)
      end
    end
    i32.const 0
    i32.load offset=1144
    call 20
    i32.const 0
    i32.load offset=1144
    call 20
    i32.const 0
    i32.load offset=1144
    call 20)
  (func (;20;) (type 4) (param i32)
    (local i32 i32)
    block  ;; label = @1
      local.get 0
      i32.eqz
      br_if 0 (;@1;)
      block  ;; label = @2
        local.get 0
        i32.load offset=76
        i32.const 0
        i32.lt_s
        br_if 0 (;@2;)
        local.get 0
        call 18
        drop
      end
      block  ;; label = @2
        local.get 0
        i32.load offset=20
        local.get 0
        i32.load offset=28
        i32.eq
        br_if 0 (;@2;)
        local.get 0
        i32.const 0
        i32.const 0
        local.get 0
        i32.load offset=36
        call_indirect (type 6)
        drop
      end
      local.get 0
      i32.load offset=4
      local.tee 1
      local.get 0
      i32.load offset=8
      local.tee 2
      i32.eq
      br_if 0 (;@1;)
      local.get 0
      local.get 1
      local.get 2
      i32.sub
      i64.extend_i32_s
      i32.const 1
      local.get 0
      i32.load offset=40
      call_indirect (type 7)
      drop
    end)
  (func (;21;) (type 0) (result i32)
    i32.const 1148)
  (table (;0;) 1 1 funcref)
  (memory (;0;) 256 256)
  (global (;0;) (mut i32) (i32.const 5244032))
  (global (;1;) (mut i32) (i32.const 0))
  (global (;2;) (mut i32) (i32.const 0))
  (export "memory" (memory 0))
  (export "__wasm_call_ctors" (func 0))
  (export "sum" (func 1))
  (export "diff" (func 2))
  (export "del" (func 3))
  (export "mult" (func 4))
  (export "get_flag21b8192d" (func 5))
  (export "generate" (func 6))
  (export "main" (func 8))
  (export "__indirect_function_table" (table 0))
  (export "__errno_location" (func 21))
  (export "__stdio_exit" (func 19))
  (export "emscripten_stack_init" (func 12))
  (export "emscripten_stack_get_free" (func 13))
  (export "emscripten_stack_get_base" (func 14))
  (export "emscripten_stack_get_end" (func 15))
  (export "stackSave" (func 9))
  (export "stackRestore" (func 10))
  (export "stackAlloc" (func 11))
  (data (;0;) (i32.const 1024) "H\00\00\00X\00\00\00Y\00\00\00X\00\00\00G\00\00\00U\00\00\00h\00\00\00d\00\00\00(\00\00\00y\00\00\00D\00\00\00/\00\00\006\00\00\000\00\00\00n\00\00\00a\00\00\00w\00\00\00(\00\00\00D\00\00\00*\00\00\00`\00\00\00L\00\00\00 \00\00\00'\00\00\00h\00\00\00b\00\00\00f\00\00\00\00\00\00\00"))
