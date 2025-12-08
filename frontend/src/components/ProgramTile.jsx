import React from 'react';
import './ProgramTile.css';

const ProgramTile = ({ program, onClick, isActive }) => {
  return (
    <div 
      className={`program-tile glass ${isActive ? 'active' : ''}`} 
      onClick={() => onClick(program)}
    >
      <div className="tile-header">
        <div className={`lang-badge ${program.type}`}>
          {program.type}
        </div>
        <h3 className="program-name" title={program.name}>{program.name}</h3>
      </div>
      
      <div className="tile-body">
        <div className="code-preview">
            {program.preview}
        </div>
        {program.description && (
            <div className="program-desc" title={program.description}>
                {program.description}
            </div>
        )}
      </div>
    </div>
  );
};

export default ProgramTile;
