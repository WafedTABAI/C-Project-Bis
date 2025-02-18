import React from 'react';
import { Question } from "../definition/Question";
import { JOEL_QUESTIONS } from "../definition/data";
import { NavBar } from './NavBar';
import QuestionComponent from './QuestionComponent'; // Import your QuestionComponent
import "../../styles/scss/common.scss";

interface JoelsAppState {
  questions: Question[];
}

class JoelsApp extends React.Component<{}, JoelsAppState> {
  constructor(props) {
    super(props);
    this.state = {
      questions: JOEL_QUESTIONS,
    };
  }

  render() {
    return (
      <div className="question-manager">
        <NavBar title="The Joel Test" subTitle="by Joel Spolsky" />
        <div className="app-container">
          {/* Render the questions */}
          {this.state.questions.map((question, index) => (
            <QuestionComponent 
              key={index} // Important: Add a unique key
              questionNumber={index + 1} 
              questionText={question.text} // Assuming 'text' property holds the question
            />
          ))}
        </div>
      </div>
    );
  }
}

export default JoelsApp;


******

/* JoelTestQuestion.css */
.joel-test-question {
  margin-bottom: 20px; /* Space between questions */
}

.browser-frame {
  border: 1px solid #ccc; /* Light gray border */
  border-radius: 5px; /* Rounded corners */
  overflow: hidden; /* Hide content that overflows the frame */
}

.title-bar {
  background-color: #eee; /* Light gray background for title bar */
  padding: 5px 10px;
  font-weight: bold;
}

.address-bar {
  background-color: #f8f8f8; /* Very light gray background */
  padding: 5px 10px;
  border-bottom: 1px solid #ddd; /* Subtle bottom border */
}

.page-content {
  padding: 20px;
}

.question-header {
  text-align: center;
  margin-bottom: 15px;
}

.question-box {
  background-color: #f0f0f0; /* Light gray background */
  padding: 15px;
  border: 1px solid #ddd; /* Slightly darker border */
}

.question-box p {
  margin: 0; /* Remove default paragraph margins */
}

import JoelTestQuestion from './JoelTestQuestion';

const MyComponent: React.FC = () => {
  return (
    <div>
      <JoelTestQuestion questionNumber={1} questionText="Do you use source control?" />
      <JoelTestQuestion questionNumber={2} questionText="Do you have a bug database?" />
      {/* ... other questions */}
    </div>
  );
};

export default MyComponent;
