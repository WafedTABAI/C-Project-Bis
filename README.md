import React from 'react';
import './JoelTestQuestion.css'; // Import your CSS file

interface JoelTestQuestionProps {
  questionNumber: number;
  questionText: string;
}

const JoelTestQuestion: React.FC<JoelTestQuestionProps> = ({ questionNumber, questionText }) => {
  return (
    <div className="joel-test-question">
      <div className="browser-frame"> {/* Mimic browser frame */}
        <div className="title-bar">Joel's Test</div>
        <div className="address-bar">
          ← → C 127.0.0.1:8080 Q ☆
        </div>
        <div className="page-content">
          <div className="question-header">
            <h1>The Joel Test</h1>
            <p>by Joel Spolsky</p>
          </div>
          <div className="question-box">
            <p>{questionNumber}) {questionText}</p>
          </div>
        </div>
      </div>
    </div>
  );
};

export default JoelTestQuestion;

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
