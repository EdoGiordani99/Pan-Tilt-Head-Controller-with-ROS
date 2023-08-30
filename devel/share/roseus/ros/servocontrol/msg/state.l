;; Auto-generated. Do not edit!


(when (boundp 'servocontrol::state)
  (if (not (find-package "SERVOCONTROL"))
    (make-package "SERVOCONTROL"))
  (shadow 'state (find-package "SERVOCONTROL")))
(unless (find-package "SERVOCONTROL::STATE")
  (make-package "SERVOCONTROL::STATE"))

(in-package "ROS")
;;//! \htmlinclude state.msg.html


(defclass servocontrol::state
  :super ros::object
  :slots (_last_cmd _step _speed _x _y ))

(defmethod servocontrol::state
  (:init
   (&key
    ((:last_cmd __last_cmd) "")
    ((:step __step) 0)
    ((:speed __speed) 0.0)
    ((:x __x) 0)
    ((:y __y) 0)
    )
   (send-super :init)
   (setq _last_cmd (string __last_cmd))
   (setq _step (round __step))
   (setq _speed (float __speed))
   (setq _x (round __x))
   (setq _y (round __y))
   self)
  (:last_cmd
   (&optional __last_cmd)
   (if __last_cmd (setq _last_cmd __last_cmd)) _last_cmd)
  (:step
   (&optional __step)
   (if __step (setq _step __step)) _step)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:serialization-length
   ()
   (+
    ;; string _last_cmd
    4 (length _last_cmd)
    ;; uint8 _step
    1
    ;; float32 _speed
    4
    ;; uint8 _x
    1
    ;; uint8 _y
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _last_cmd
       (write-long (length _last_cmd) s) (princ _last_cmd s)
     ;; uint8 _step
       (write-byte _step s)
     ;; float32 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint8 _x
       (write-byte _x s)
     ;; uint8 _y
       (write-byte _y s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _last_cmd
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _last_cmd (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _step
     (setq _step (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32 _speed
     (setq _speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint8 _x
     (setq _x (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _y
     (setq _y (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get servocontrol::state :md5sum-) "c95f0a0c1b57d8b8eaffcee8de0dcceb")
(setf (get servocontrol::state :datatype-) "servocontrol/state")
(setf (get servocontrol::state :definition-)
      "string last_cmd
uint8 step
float32 speed
uint8 x
uint8 y
")



(provide :servocontrol/state "c95f0a0c1b57d8b8eaffcee8de0dcceb")


