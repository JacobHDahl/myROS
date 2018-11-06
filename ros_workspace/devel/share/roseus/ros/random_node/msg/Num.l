;; Auto-generated. Do not edit!


(when (boundp 'random_node::Num)
  (if (not (find-package "RANDOM_NODE"))
    (make-package "RANDOM_NODE"))
  (shadow 'Num (find-package "RANDOM_NODE")))
(unless (find-package "RANDOM_NODE::NUM")
  (make-package "RANDOM_NODE::NUM"))

(in-package "ROS")
;;//! \htmlinclude Num.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass random_node::Num
  :super ros::object
  :slots (_header _start _num2 _num1 ))

(defmethod random_node::Num
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:start __start) (instance std_msgs::Time :init))
    ((:num2 __num2) 0)
    ((:num1 __num1) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _start __start)
   (setq _num2 (round __num2))
   (setq _num1 (round __num1))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:start
   (&rest __start)
   (if (keywordp (car __start))
       (send* _start __start)
     (progn
       (if __start (setq _start (car __start)))
       _start)))
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; std_msgs/Time _start
    (send _start :serialization-length)
    ;; int16 _num2
    2
    ;; int16 _num1
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; std_msgs/Time _start
       (send _start :serialize s)
     ;; int16 _num2
       (write-word _num2 s)
     ;; int16 _num1
       (write-word _num1 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; std_msgs/Time _start
     (send _start :deserialize buf ptr-) (incf ptr- (send _start :serialization-length))
   ;; int16 _num2
     (setq _num2 (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _num1
     (setq _num1 (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get random_node::Num :md5sum-) "5ab4760c592fe1830e3587fa9b42e8b1")
(setf (get random_node::Num :datatype-) "random_node/Num")
(setf (get random_node::Num :definition-)
      "Header header
std_msgs/Time start
int16 num2
int16 num1

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: std_msgs/Time
time data

")



(provide :random_node/Num "5ab4760c592fe1830e3587fa9b42e8b1")


