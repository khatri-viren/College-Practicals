import React from 'react'
import "./Screen.css";

const Screen = ({ value }) => {
  return (
    <div className="screen" mode="single" max={70}>
      {value}
    </div>
  );
};

export default Screen