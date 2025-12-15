import React from "react";

const GradePage = (props) => {
      const { studentName, grade, subject, description } = props;
      return (<div>
            <h2>{studentName}</h2>
            <p>{subject}: {grade}</p>
            <p>{description}</p>
            <button>Appeal</button>
            <button>Submit</button>
      </div>);
}
export default GradePage
